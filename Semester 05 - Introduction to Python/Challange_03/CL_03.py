import re
import types
import secret

def is_interesting(func):
    if type(func) is types.FunctionType:
        return True

    try:
        n1 = func(4)
        n2 = func(5)
        if n1 == 4**2 and n2 == 0:
            return True
    except:
        pass

    try:
        st = func("string1", "string2")
        if st == "string1string2":
            return True
    except:
        pass

    try:
        func()
    except TypeError as exc:
        if str(exc) == "Опаааааа, тука има нещо нередно.":
            return True
    except BaseException:
        return True
    
    return False

def methodify():
    interesting_methods = {}
    levels = []
    levels.append(secret)

    while levels:
        this_level = levels.pop(0)
        for element_name in dir(this_level):
            if re.search("^__(.+)__$", element_name):
                continue
            element = getattr(this_level, element_name)
            if type(element) is type:
                continue
            
            if (type(element) is types.MethodType 
                or type(element) is types.FunctionType):
                if (re.search("^[A-Z0-9]$", element_name) 
                    and is_interesting(element)):
                    interesting_methods[element_name] = element
                continue
        
            if not re.search("[Cc]lue", element_name):
                continue
            
            levels.append(element)

    fn = []
    for c in "FN0123456789MI":
            fn.append(interesting_methods[c])
    return tuple(fn)