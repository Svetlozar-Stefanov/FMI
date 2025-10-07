import math
import copy
import re

class Potion:
    @staticmethod
    def round_down(n):
        temp = math.floor(n)
        if n - temp <= 0.5:
            return math.floor(n)
        return math.ceil(n)

    def _wholeness_check(self, func):
        def check(args):
            self._validate_not_depleted()
            self._validate_not_used()
            return func(args)
        return check

    def _depleted_check(self, effect, func):
        def check(args):
            if effect in self.depleted_effects:
                if self.depleted_effects[effect]:
                    raise TypeError("Effect is depleted.")
                self.depleted_effects[effect] = True
            return func(args)
        return check
    
    def _apply_intensity(self, effect, func):
        def apply(args):
            if effect in self.intensity:
                for _ in range(self.intensity[effect]):
                    func(args)
        return apply
    
    def _copy(self):
        copy_potion = Potion({}, self.duration)
        for effect in self.effects:
            copy_potion.effects[effect] = self.effects[effect]
            copy_potion.depleted_effects[effect] = self.depleted_effects[effect]
            copy_potion.intensity[effect] = self.intensity[effect]
            setattr(copy_potion, effect, copy_potion._wholeness_check(
                copy_potion._depleted_check(
                    effect, copy_potion._apply_intensity(
                        effect, copy_potion.effects.get(effect)))))
        return copy_potion

    def _validate_not_used(self):
        if self.used:
            raise TypeError("Potion is now part of something bigger than itself.")

    def _validate_not_depleted(self):
        if self.depleted:
            raise TypeError("Potion is depleted.")

    def _increase_potential(self, scale):
        multiplied_potion = self._copy()
        for effect in multiplied_potion.intensity:
            multiplied_potion.intensity[effect] *= scale
        self.used = True
        return multiplied_potion
    
    def _decrease_potential(self, scale):
        divided_potion = self._copy()
        for effect in divided_potion.intensity:
            divided_potion.intensity[effect] = Potion.round_down(
                divided_potion.intensity[effect] * scale)
        self.used = True
        return divided_potion

    def __init__(self, effects, duration):
        self.used = False
        self.depleted = False
        self.effects = effects
        self.depleted_effects = {}
        self.intensity = {}
        for effect in effects:
            self.depleted_effects[effect] = False
            self.intensity[effect] = 1
            setattr(self, effect, self._wholeness_check(
                self._depleted_check(
                    effect, self._apply_intensity(
                        effect, effects.get(effect)))))
        self.duration = duration
    
    def apply(self, target):
        self._validate_not_depleted()
        self._validate_not_used()
        for effect in sorted(self.effects.keys(), 
                             key=lambda name: sum(ord(c) for c in name),
                             reverse=True):
            if not self.depleted_effects[effect]:
                getattr(self, effect)(target)
        self.depleted = True

    def __add__(self, other):
        self._validate_not_depleted()
        self._validate_not_used()
        other._validate_not_depleted()
        other._validate_not_used()
        compound = self._copy()
        for effect in other.effects:
            if effect in compound.effects:
                compound.intensity[effect] += other.intensity[effect]
            else:
                compound.effects[effect] = other.effects[effect]
                compound.depleted_effects[effect] = other.depleted_effects[effect]
                compound.intensity[effect] = other.intensity[effect]
                setattr(compound, effect, compound._wholeness_check(
                    compound._depleted_check(
                        effect, compound._apply_intensity(
                            effect, compound.effects.get(effect)))))
        self.used = True
        other.used = True
        return compound

    def __mul__(self, scale):
        self._validate_not_depleted()
        self._validate_not_used()
        if scale > 1:
            return self._increase_potential(scale)
        return self._decrease_potential(scale)
    
    def __sub__(self, other):
        self._validate_not_depleted()
        self._validate_not_used()
        other._validate_not_depleted()
        other._validate_not_used()
        purified_potion = self._copy()
        for effect in other.effects:
            if effect in purified_potion.effects:
                if purified_potion.intensity[effect] > other.intensity[effect]:
                    purified_potion.intensity[effect] -= other.intensity[effect]
                else:
                    purified_potion.depleted_effects.pop(effect)
                    purified_potion.intensity.pop(effect)
                    purified_potion.effects.pop(effect)
                    delattr(purified_potion, effect)
            else:
                raise TypeError("Cannot remove non-existent effect.")
        self.used = True
        other.used = True
        return purified_potion
    
    def __truediv__(self, scale):
        self._validate_not_depleted()
        self._validate_not_used()
        potions = []
        for _ in range(scale):
            potion = self._copy()
            for effect in potion.intensity:
                potion.intensity[effect] //= scale
            potions.append(potion)
        self.used = True
        return tuple(potions)
    
    def __eq__(self, other):
        return (self.effects == other.effects and self.intensity == other.intensity)

    def __lt__(self, other):
        return sum(self.intensity.values()) < sum(other.intensity.values())
    
    def __gt__(self, other):
        return sum(self.intensity.values()) > sum(other.intensity.values())


class ГоспожатаПоХимия:
    def __init__(self):
        self.durations = {}
        self.targets = {}
        self.effects = {}

    def apply(self, target, potion):
        old_target = copy.deepcopy(target)
        potion.apply(target)
        self.durations[id(potion)] = potion.duration
        if id(target) not in self.targets:
            self.targets[id(target)] = old_target
        self.effects[id(potion)] = [target, self.targets[id(target)]]

    def tick(self):
        for effect in self.durations:
            self.durations[effect] -= 1
            if  self.durations[effect] == 0:
                target, old_target = self.effects[effect]
                for attrib in target.__dir__():
                    if re.search("^__[A-Za-z_0-9]+__$", attrib):
                        continue
                    setattr(target, attrib, getattr(old_target, attrib))