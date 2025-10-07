import itertools

def organize(cars, students):
    for perm in itertools.permutations(students, len(students)):
        all_seated = True
        car_iter = iter(cars)
        car = next(car_iter)
        for student in perm:
            try:
                car.add_student(student)
            except:
                try:
                    car = next(car_iter)
                except StopIteration:
                    all_seated = False
                    break
                car.add_student(student)
            all_seated = student.is_comfy()
            if not all_seated: break
        if not all_seated: continue
        return True
    return False