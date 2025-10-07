import unittest
from HW_03 import Kid
from HW_03 import Host
from HW_03 import FluxCapacitor


class Test(unittest.TestCase):
    def test_get_victim_one_victim(self):
        kid_1 = Kid((1, 2), 6)
        kid_2 = Kid((3, 4), 7)
        kid_3 = Kid((5, 6), 8)

        host_1 = Host((3, 0), [(30, 1)])
        host_2 = Host((2, 5), [(20, 1)])
        host_3 = Host((7, 7), [(10, 1)])

        flux = FluxCapacitor({kid_1, kid_2, kid_3, host_1, host_2, host_3})

        self.assertEqual(flux.get_victim(), {kid_1},
                         "Victim must be retrieved correctly")

    def test_get_victim_no_victims(self):
        kid_1 = Kid((1, 2), 6)
        kid_2 = Kid((3, 4), 7)
        kid_3 = Kid((5, 6), 8)

        host_1 = Host((3, 0), [(10, 1)])
        host_2 = Host((2, 5), [(10, 1)])
        host_3 = Host((7, 7), [(10, 1)])

        flux = FluxCapacitor({kid_1, kid_2, kid_3, host_1, host_2, host_3})

        self.assertEqual(flux.get_victim(), None,
                         "Non-victim case must be handled correctly")

    def test_get_victim_two_kids_three_hosts(self):
        kid_1 = Kid((1, 1), 6)
        kid_2 = Kid((-1, 1), 7)

        host_1 = Host((-1, -1), [(10, 1)])
        host_2 = Host((1, -1), [(10, 1)])
        host_3 = Host((2, 3), [(11, 1)])

        flux = FluxCapacitor({kid_1, kid_2, host_1, host_2, host_3})

        self.assertEqual(flux.get_victim(), {kid_2},
                         "Victims must be calculated correctly based on distance")

    def test_get_victim_two_kids_same_distance_to_host(self):
        kid_1 = Kid((-1, -1), 5)
        kid_2 = Kid((1, -1), 6)

        host = Host((0, 3), [(21, 1)])

        flux = FluxCapacitor({kid_1, kid_2, host})

        self.assertEqual(flux.get_victim(), {kid_2},
                         "The kid with the higher initiative value must get the kandy")
        
    def test_get_victim_multiple_victims(self):
        kid_1 = Kid((1, 2), 6)
        kid_2 = Kid((3, 4), 7)
        kid_3 = Kid((5, 6), 8)

        host_1 = Host((3, 0), [(21, 1)])
        host_2 = Host((2, 5), [(21, 1)])
        host_3 = Host((7, 7), [(21, 1)])

        flux = FluxCapacitor({kid_1, kid_2, kid_3, host_1, host_2, host_3})

        self.assertEqual(flux.get_victim(), {kid_1, kid_2, kid_3},
                         "Victims must be retrieved correctly")

    def test_get_victim_no_candies(self):
        kid_1 = Kid((1, 2), 6)
        kid_2 = Kid((3, 4), 7)
        kid_3 = Kid((5, 6), 8)

        host_1 = Host((3, 0), [])
        host_2 = Host((2, 5), [])
        host_3 = Host((7, 7), [])

        flux = FluxCapacitor({kid_1, kid_2, kid_3, host_1, host_2, host_3})

        self.assertEqual(flux.get_victim(), None,
                         "Victims must be retrieved correctly")
        
    def test_get_victim_two_neighbors_same_distance(self):
        kid = Kid((1, 1), 6)

        host_1 = Host((0, 3), [(19, 1)])
        host_2 = Host((2, 3), [(2, 1)])

        flux = FluxCapacitor({kid, host_1, host_2})
        result_kid = flux.get_victim()

        self.assertEqual(result_kid, {kid})
        self.assertEqual(result_kid.pop().get_position(), (2, 3),
                        "The kid must go to the host with the smaller x-value first")

    def test_get_victim_two_neighbors_same_distance_and_same_x_value(self):
        kid = Kid((0, 0), 6)

        host_1 = Host((2, 2), [(2, 1)])
        host_2 = Host((2, -2), [(19, 1)])

        flux = FluxCapacitor({kid, host_1, host_2})
        result_kid = flux.get_victim()

        self.assertEqual(result_kid, {kid})
        self.assertEqual(result_kid.pop().get_position(), (2, 2),
                        "The kid must go to the host with the smaller y-value first")
        
if __name__ == "__main__":
    unittest.main()