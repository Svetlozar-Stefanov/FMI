def contradict(argument):
    if type(argument) is bool:
        return not argument
    elif type(argument) is str:
        return argument[::-1]
    else:
        return -argument

def no_it_isnt(arguments):
    return list((map(contradict, arguments)))[::-1]