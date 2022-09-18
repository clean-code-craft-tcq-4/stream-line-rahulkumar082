def is_in_range(present_value, min_value, max_value):
    return is_not_greater(present_value, max_value) and is_not_lesser(present_value, min_value)

def is_not_greater(present_value, max_value):
    return (present_value < max_value)

def is_not_lesser(present_value, min_value):
    return (present_value > min_value)