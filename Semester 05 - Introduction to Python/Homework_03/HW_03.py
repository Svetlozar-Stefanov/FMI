import math

class Candy:
    def __init__(self, mass, uranium):
        self._mass = mass
        self._uranium = uranium

    def get_uranium_quantity(self):
        return self._mass * self._uranium

    def get_mass(self):
        return self._mass


class Person:
    def __init__(self, position):
        self._position = position
    
    def get_position(self):
        return self._position
    
    def set_position(self, position):
        self._position = position

    def distance_to(self, other):
        return math.sqrt((self._position[0] - other._position[0])**2 
                         + (self._position[1] - other._position[1])**2)


class Kid(Person):

    MAX_CANDIES = 20

    def __init__(self, position, initiative):
        super().__init__(position)
        self._initiative = initiative
        self._visited_hosts = set()
        self._candies = set()
        self._uranium_in_basket = 0

    def get_initiative(self):
        return self._initiative
    
    def add_candy(self, candy):
        self._uranium_in_basket += candy.get_uranium_quantity()
        self._candies.add(candy)

    def is_critical(self):
        if self._uranium_in_basket > self.MAX_CANDIES:
            return True
        return False
    
    def visit(self, host):
        self._visited_hosts.add(host)
        self.set_position(host.get_position())

    def has_visited(self, host):
        return host in self._visited_hosts
    

class Host(Person):
    def __init__(self, position, candies):
        super().__init__(position)
        self._candies = []
        self._visitors = []
        for candy in candies:
            self._candies.append(Candy(*candy))

    def remove_candy(self, pick_candy_func):
        if not self._candies:
            return None
        candy = pick_candy_func(self._candies)
        self._candies.remove(candy)
        return candy
        
    def accept_visitor(self, kid):
        self._visitors.append(kid)

    def get_compare_list(self, kid):
        return [
            kid.distance_to(self),
            self._position[0],
            self._position[1],
            self
        ]

    def give_out_candies(self, pick_candy_func):
        self._visitors.sort(key=lambda kid: kid.get_initiative())
        while self._visitors:
            kid = self._visitors.pop()
            candy = self.remove_candy(pick_candy_func)
            if candy is not None:
                kid.add_candy(candy)

        
class FluxCapacitor:
    def __init__(self, participants):
        self._kids = []
        self._hosts = []
        self._victims = set()
        for participant in participants:
            if type(participant) is Kid:
                self._kids.append(participant)
            if type(participant) is Host:
                self._hosts.append(participant)

    def get_victim(self):
        kids_who_visited_all = set()
        while (len(kids_who_visited_all) != len(self._kids) 
               and not self._victims):
            for kid in self._kids:
                if kid in kids_who_visited_all:
                    continue
                closest_host = self._get_closest_host(kid)
                if closest_host is None:
                    kids_who_visited_all.add(kid)
                    continue
                kid.visit(closest_host)
                closest_host.accept_visitor(kid)
            for host in self._hosts:
                host.give_out_candies(self._pick_candy)
            for kid in self._kids:
                if kid.is_critical():
                    self._victims.add(kid)
        return self._victims or None
    
    def _get_closest_host(self, kid):
        closest_host = [None]
        for host in self._hosts:
            if kid.has_visited(host):
                continue
            if None in closest_host:
                closest_host = host.get_compare_list(kid)
                continue
            closest_host = min(closest_host, host.get_compare_list(kid))
        return closest_host[-1]
    
    def _pick_candy(self, candies):
        return max(candies, key=(lambda candy: candy.get_mass()))