from helper_scripts.check_range import is_in_range


class State_Of_Charge:
    def __init__(self) -> None:
        self.min_percent = 20
        self.max_percent = 80

    def validate(self, input_percent):
        return is_in_range(input_percent, self.min_percent, self.max_percent)
