#include <iostream>
#include <fstream>

const int DATA_SIZE = 128;
const int MAX_USERS = 100;
const int BUFF_SIZE = 1024;

struct User
{
    char Name[DATA_SIZE];
    char Email[DATA_SIZE];
    char Password[DATA_SIZE];
};

struct System
{
    User users[MAX_USERS];

    unsigned CurrentUsers = 0;
};

bool isEqual(const char* fn1, const char* fn2)
{
	for (int i = 0; i < strlen(fn2); i++)
	{
		if (fn1[i] != fn2[i])
		{
			return false;
		}
	}

	return true;
}

void copy(char* str1, const char* str2) {
	for (int i = 0; i < strlen(str2) + 1; i++)
	{
		str1[i] = str2[i];
	}
}

void readUsers(System& system, const char* fname, std::fstream &file) 
{
    file.open(fname, std::fstream::in);
    if (file.is_open())
    {
		while (!file.eof())
		{
			char buffer[BUFF_SIZE];
			int indx = 0;
			char name[DATA_SIZE];
			char email[DATA_SIZE];
			char pass[DATA_SIZE];

			file.getline(buffer, BUFF_SIZE);

			int pos = 0;
			int i = 0;
			while (buffer[i] != '\0')
			{
				if (buffer[i] == ',')
				{
					switch (pos)
					{
					case 0: name[indx++] = '\0'; break;
					case 1: email[indx++] = '\0'; break;
					case 2: pass[indx++] = '\0'; break;
					default:
						break;
					}
					pos++;
					indx = 0;
				}
				else
				{
					switch (pos)
					{
					case 0: name[indx++] = buffer[i]; break;
					case 1: email[indx++] = buffer[i]; break;
					case 2: pass[indx++] = buffer[i]; break;
					default:
						break;
					}
				}

				if (buffer[i + 1] == '\0')
				{
					pass[indx++] = '\0';
				}

				i++;
			}
			
			User user;
			copy(user.Name, name);
			copy(user.Email, email);
			copy(user.Password, pass);

			system.users[system.CurrentUsers++] = user;
		}

		file.close();
    }
}

void saveUsers(const char* fileName, System& users)
{
	std::fstream file;
	file.open(fileName, std::fstream::out);
	if (file.is_open())
	{
		for (int i = 0; i < users.CurrentUsers; i++)
		{
			file << users.users[i].Name << "," << users.users[i].Email << "," << users.users[i].Password << '\n';
		}
	}

	file.close();
}

void registerNewUser(User newUser, System &system) 
{
	system.users[system.CurrentUsers++] = newUser;
}

void Login(const char * email, const char * pass, System &system) 
{
	for (int i = 0; i < system.CurrentUsers; i++)
	{
		if (isEqual(system.users[i].Email, email) 
			&& isEqual(system.users[i].Password, pass))
		{
			std::cout << "Successful login!\n";
		}
	}
}

int main()
{
    System system;
	std::fstream file;
	readUsers(system, "users.txt", file);

	User user;
	copy(user.Name, "Petkan");
	copy(user.Email, "pet.com");
	copy(user.Password, "123");

	registerNewUser(user, system);

	Login("pet.com", "123", system);

	saveUsers("users.txt", system);

}