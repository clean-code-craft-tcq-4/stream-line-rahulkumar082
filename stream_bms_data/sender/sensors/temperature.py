from helper_scripts.check_range import is_in_range


class Temperature:
    def __init__(self) -> None:
        self.min_value = 5
        self.max_value = 45

    def validate(self, present_value):
        return is_in_range(present_value, self.min_value, self.max_value)