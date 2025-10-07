def logic_mixin_factory(mass, mass_attr_name, material, material_attr_name, float_method_name):
    class WitchTrial:
        def is_a_witch(self):
            is_witch = False
            if mass_attr_name in dir(self):
                is_witch = is_witch or (mass == getattr(self, mass_attr_name))
            if material_attr_name in dir(self):
                is_witch = is_witch or (material == getattr(self, material_attr_name))
            if(is_witch or float_method_name in dir(self)):
                return "Burn her!"
            return "No, but it's a pity, cuz she looks like a witch!"
    return WitchTrial