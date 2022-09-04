from helper_scripts.check_range import is_in_range


class State_Of_Charge:
    def __init__(self) -> None:
        self.min_value = 20
        self.max_value = 80

    def validate(self, input_percent):
        return is_in_range(input_percent, self.min_value, self.max_value)
