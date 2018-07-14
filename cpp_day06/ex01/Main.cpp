// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/11 12:20:32 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/11 12:20:33 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

struct Data { std::string src1; int nb; std::string src2; };
struct InitData { char src1[8]; int nb; char src2[8]; };

void *serialize( void ) {
	InitData *data = new InitData;
	char rand_char[] = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	srand(clock());
	for (int index = 0; index < 8; index++)
	{
		data->src1[index] = rand_char[(rand() * std::time(nullptr)) % (sizeof(rand_char) - 1)];
		data->src2[index] = rand_char[rand() % (sizeof(rand_char) - 1)];
	}
	data->nb = 2147483647;//std::time(nullptr) % sizeof(Data);
	std::cout << std::endl;

	std::cout << ">>>>>>>>>>>>>>>>>> serialize part <<<<<<<<<<<<<<<<<<<<<<"<< std::endl << std::endl;
	std::cout << "void *serialize( void )  " << "string src1  " << data->src1 << std::endl;
	std::cout << "void *serialize( void )  " << "int nb  " << data->nb << std::endl;
	std::cout << "void *serialize( void )  " << "string src2  " << data->src2 << std::endl;
	std::cout << std::endl;
	return reinterpret_cast<void*>(data);
}

Data *deserialize( void *raw ) {
	Data *data = new Data;
	char *src1 = reinterpret_cast<char*>(raw);
	char *src2 = src1 + (8 * sizeof(char) + sizeof(int));
	data->nb = *reinterpret_cast<int*>(src1 + (8 * sizeof(char)));
	data->src1 = std::string(src1);
	data->src1.resize(8);
	data->src2 = std::string(src2);
	data->src2.resize(8);

	std::cout << ">>>>>>>>>>>>>>>>>> deserialize part <<<<<<<<<<<<<<<<<<<<<<"<< std::endl << std::endl;
	std::cout << "Data *deserialize( void *raw )  " << "src1  " << data->src1 << std::endl;
	std::cout << "Data *deserialize( void *raw )  " << "nb  " << data->nb << std::endl;
	std::cout << "Data *deserialize( void *raw )  " << "src2  " << data->src2 << std::endl;
	std::cout << std::endl;
	delete reinterpret_cast<InitData*>(raw);
	return data;
}

int main( void ) {
	Data *data = deserialize(serialize());

	std::cout << ">>>>>>>>>>>>>>>>>> main part <<<<<<<<<<<<<<<<<<<<<<"<< std::endl << std::endl;
	std::cout << "DATA" << std::endl;
	std::cout << "scr1 |" << data->src1 << std::endl;
	std::cout << "nb |"<< data->nb << std::endl;
	std::cout << "src2 |" << data->src2 << std::endl;
	std::cout << std::endl;
	delete data;
	return 0;
}
