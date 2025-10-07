import pytest

from HW_04 import Potion, ГоспожатаПоХимия


class Target:
    def __init__(self):
        self.size = 0.5
        self.fire_dmg_resistance = 0
        self.water_dmg_resistance = 0
        self.earth_dmg_resistance = 0
        self.air_dmg_resistance = 0
        self.bludgeoning_dmg_resistance = 0
        self.slashing_dmg_resistance = 0
        self.piercing_dmg_resistance = 0

    def __getitem__(self, index):
        return (self.size, self.fire_dmg_resistance, self.water_dmg_resistance,
                self.earth_dmg_resistance, self.air_dmg_resistance, self.bludgeoning_dmg_resistance,
                self.slashing_dmg_resistance, self.piercing_dmg_resistance)[index]

    def dummy_method_that_does_nothing_in_particular(self):
        print('something')


def elemental_dmg_immunity(target):
    target.fire_dmg_resistance = 1.0  # Percentage value between 0 and 1
    target.water_dmg_resistance = 1.0
    target.earth_dmg_resistance = 1.0
    target.air_dmg_resistance = 1.0


def physical_dmg_immunity(target):
    target.bludgeoning_dmg_resistance = 1.0
    target.slashing_dmg_resistance = 1.0
    target.piercing_dmg_resistance = 1.0


def test_effect_executes_only_once():
    target = Target()
    old_target_size = target.size

    grow_potion = Potion({'grow': lambda target: setattr(target, 'size', target.size * 2)}, duration=2)
    grow_potion.grow(target)

    assert target.size == old_target_size * 2

    with pytest.raises(TypeError, match=r'^Effect is depleted.$'):
        grow_potion.grow(target)


def test_different_effects_are_summed_properly():
    target = Target()

    grow_potion = Potion({'grow': lambda target: setattr(target, 'size', target.size * 2)}, duration=2)
    immunity_potion = Potion({'make_elemental_immune': elemental_dmg_immunity,
                              'make_physical_immune': physical_dmg_immunity},
                             duration=1)

    grow_and_immunity_potion = grow_potion + immunity_potion

    grow_and_immunity_potion.grow(target)
    grow_and_immunity_potion.make_elemental_immune(target)
    grow_and_immunity_potion.make_physical_immune(target)

    for attribute in target:
        assert attribute == 1


def test_same_effects_are_summed_properly():
    target_1 = Target()
    target_1.size = 5
    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}
    grow_potion = Potion(effect, duration=2)
    grow_potion.grow(target_1)

    assert target_1.size == 10

    target_2 = Target()
    target_2.size = 5
    triple_grow_potion = Potion(effect, duration=2) + Potion(effect, duration=2) + Potion(effect, duration=2)
    triple_grow_potion.grow(target_2)
    assert target_2.size == 40


def test_multiplication_int():
    target = Target()
    target.size = 5
    grow_potion = Potion({'grow': lambda target: setattr(target, 'size', target.size * 2)}, duration=2)
    triple_grow_potion = grow_potion * 3
    triple_grow_potion.grow(target)
    assert target.size == 40


def test_multiplication_float():
    target = Target()
    target.size = 5
    grow_potion = Potion({'grow': lambda target: setattr(target, 'size', target.size * 2)}, duration=2)
    triple_grow_potion = grow_potion * 3
    diluted_grow_potion = triple_grow_potion * 0.33
    diluted_grow_potion.grow(target)
    assert target.size == 10


def test_multiplication_zero():
    target = Target()
    target.size = 5
    grow_potion = Potion({'grow': lambda target: setattr(target, 'size', target.size * 2)}, duration=2)
    weak_grow_potion = grow_potion * 0

    with pytest.raises(TypeError, match=r'^Effect is depleted.$'):
        weak_grow_potion.grow(target)


def test_rounding():
    assert Potion.round_down(0.5) == 0
    assert Potion.round_down(3.6) == 4
    assert Potion.round_down(9.9) == 10
    assert Potion.round_down(9.4445) == 9


def test_purifying_basic_case():
    target = Target()
    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}

    grow_potion = Potion(effect, duration=2)
    immunity_potion = Potion({'make_elemental_immune': elemental_dmg_immunity,
                              'make_physical_immune': physical_dmg_immunity},
                             duration=1)

    grow_and_immunity_potion = grow_potion + immunity_potion

    grow_potion_vol_2 = Potion(effect, duration=2)

    purified_immunity_potion = grow_and_immunity_potion - grow_potion_vol_2

    purified_immunity_potion.make_elemental_immune(target)
    purified_immunity_potion.make_physical_immune(target)

    with pytest.raises(AttributeError):
        purified_immunity_potion.grow(target)


def test_purifying_lower_intensity_of_right_operand():
    target = Target()

    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}

    grow_potion_x_5 = Potion(effect, duration=2) * 5
    grow_potion_x_2 = Potion(effect, duration=3) * 2

    grow_potion_x_3 = grow_potion_x_5 - grow_potion_x_2

    target.size = 5

    grow_potion_x_3.grow(target)

    assert target.size == 40


def test_purifying_same_intensity_of_both_operands():
    target = Target()

    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}

    grow_potion_x_5 = Potion(effect, duration=2) * 5
    grow_potion_x_5_vol_2 = Potion(effect, duration=2) * 5

    grow_potion_x_0 = grow_potion_x_5 - grow_potion_x_5_vol_2

    with pytest.raises(AttributeError):
        grow_potion_x_0.grow(target)


def test_purifying_greater_intensity_of_right_operand():
    target = Target()

    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}

    grow_potion_x_2 = Potion(effect, duration=3) * 2
    grow_potion_x_5 = Potion(effect, duration=2) * 5

    useless_grow_potion = grow_potion_x_2 - grow_potion_x_5

    with pytest.raises(AttributeError):
        useless_grow_potion.grow(target)


def test_division_basic_case():
    target = Target()
    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}
    target.size = 5

    triple_grow_potion = Potion(effect, duration=3) * 3
    diluted_grow_potion, diluted_grow_potion_vol_2, diluted_grow_potion_vol_3 = triple_grow_potion / 3
    diluted_grow_potion.grow(target)
    assert target.size == 10
    diluted_grow_potion_vol_2.grow(target)
    assert target.size == 20
    diluted_grow_potion_vol_3.grow(target)
    assert target.size == 40

def test_an_already_used_potion_addition():
    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}
    grow_potion = Potion(effect, duration=2)
    grow_potion_vol_2 = Potion(effect, duration=2)
    target = Target()
    _ = grow_potion + grow_potion_vol_2

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        grow_potion.grow(target)

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        grow_potion_vol_2.grow(target)

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        _ = grow_potion + grow_potion_vol_2


def test_an_already_used_potion_multiplication():
    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}
    grow_potion = Potion(effect, duration=2)
    target = Target()
    _ = grow_potion * 8

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        grow_potion.grow(target)

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        _ = grow_potion * 9


def test_an_already_used_potion_subtraction():
    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}
    grow_potion = Potion(effect, duration=2)
    grow_potion_vol_2 = Potion(effect, duration=2)
    target = Target()
    _ = grow_potion - grow_potion_vol_2

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        grow_potion.grow(target)

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        grow_potion_vol_2.grow(target)

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        _ = grow_potion - grow_potion_vol_2


def test_an_already_used_potion_division():
    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}
    grow_potion = Potion(effect, duration=2)
    target = Target()
    triple_grow_potion = grow_potion * 3
    _, _, _ = triple_grow_potion / 3

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        grow_potion.grow(target)

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        triple_grow_potion.grow(target)

    with pytest.raises(TypeError, match=r'^Potion is now part of something bigger than itself.$'):
        _ = triple_grow_potion / 3


def test_comparison():
    effect = {'grow': lambda target: setattr(target, 'size', target.size * 2)}

    grow_potion = Potion(effect, duration=2)
    double_grow_potion = Potion(effect, duration=2) * 2

    immunity_potion = Potion({'make_elemental_immune': elemental_dmg_immunity,
                              'make_physical_immune': physical_dmg_immunity},
                             duration=1)

    assert grow_potion == grow_potion # True
    assert Potion(effect, duration=2) + Potion(effect, duration=2) == double_grow_potion # True
    assert not grow_potion < grow_potion  # False
    assert double_grow_potion > grow_potion # True
    assert immunity_potion > grow_potion # True
    assert not double_grow_potion < immunity_potion  # False
    assert not double_grow_potion > immunity_potion  # False


def test_apply_basic_case():
    target = Target()
    dimitrichka = ГоспожатаПоХимия()

    grow_potion = Potion({'grow': lambda target: setattr(target, 'size', target.size * 2)}, duration=2)
    immunity_potion = Potion({'make_elemental_immune': elemental_dmg_immunity,
                              'make_physical_immune': physical_dmg_immunity},
                             duration=1)
    grow_and_immunity_potion = grow_potion + immunity_potion

    dimitrichka.apply(target, grow_and_immunity_potion)

    for attribute in target:
        assert attribute == 1

    with pytest.raises(TypeError, match=r'^Potion is depleted.$'):
        _ = grow_and_immunity_potion / 3

    with pytest.raises(TypeError, match=r'^Potion is depleted.$'):
        grow_and_immunity_potion.grow(target)


def test_valid_mass_order():
    target = Target()
    dimitrichka = ГоспожатаПоХимия()

    target.size = 5
    grow_potion = Potion({'grow': lambda target: setattr(target, 'size', target.size * 2)}, duration=2)
    also_grow_potion = Potion({'oh': lambda target: setattr(target, 'size', target.size + 5)}, duration=1)
    grow_potion_too = Potion({'krava': lambda target: setattr(target, 'size', target.size * 4)}, duration=1)

    combo = grow_potion + also_grow_potion + grow_potion_too

    dimitrichka.apply(target, combo)

    assert target.size == 45


def test_tick_basic_case():
    target = Target()
    narco = ГоспожатаПоХимия()
    effect = {'grow': lambda something: setattr(something, 'size', something.size * 2)}
    grow_potion = Potion(effect, duration=2)

    target.size = 5
    narco.apply(target, grow_potion)
    assert target.size == 10
    narco.tick()
    assert target.size == 10
    narco.tick()
    assert target.size == 5

def test_tick_basic_nasty_case():
    target = Target()
    narco = ГоспожатаПоХимия()
    effect = {'grow': lambda something: setattr(something, 'size', something.size * 2)}
    grow_potion = Potion(effect, duration=2)
    grow_potion_vol_2 = Potion(effect, duration=2)

    target.size = 5
    narco.apply(target, grow_potion)
    assert target.size == 10
    narco.tick()
    narco.apply(target, grow_potion_vol_2)
    assert target.size == 20
    narco.tick()
    assert target.size == 10
    narco.tick()
    assert target.size == 5