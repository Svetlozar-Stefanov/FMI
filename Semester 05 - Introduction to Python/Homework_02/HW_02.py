def plugboard(word, plugboard_position):
    changed_word = ""
    for letter in word:
        for letter_pair in plugboard_position:
            if letter in letter_pair:
                letter = list(letter_pair - {letter})[0]
        changed_word += letter
    return changed_word

def rotor(word, rotor_position):
    changed_word = ""
    for letter in word:
        if letter in rotor_position:
            letter = rotor_position[letter]
        changed_word += letter
    return changed_word

def enigma_encrypt(plugboard_position, rotor_position):
    def encrypt_function(func):
        def encrypted_call(word):
            word = plugboard(word, plugboard_position)
            word = rotor(word, rotor_position)
            return func(word)
        return encrypted_call
    return encrypt_function

def enigma_decrypt(plugboard_position, rotor_position):
    rotor_position = {v:k for k, v in rotor_position.items()}
    def decrypt_function(func):
        def decrypted_call(word):
            word = rotor(word, rotor_position)
            word = plugboard(word, plugboard_position)
            return func(word)
        return decrypted_call
    return decrypt_function