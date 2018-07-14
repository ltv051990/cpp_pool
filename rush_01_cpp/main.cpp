/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 12:52:13 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/15 12:28:09 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayContainer.hpp"
#include "Cor.hpp"

void usage(){
	std::cout << std::endl << "Usage: ft_gkrellm [visual mode] [flags mode]" << std::endl;
	std::cout << std::endl << "visual mode: [-t] text mode; [-v] graphic mode" << std::endl;
	std::cout << std::endl << "flags mode:" << std::endl;
	std::cout << "[ os  ] OS info mudule" << std::endl;
	std::cout << "[ hu  ] OS hostname && username" << std::endl;
	std::cout << "[ dt  ] date && time info" << std::endl;
	std::cout << "[ pi  ] process info" << std::endl;
	std::cout << "[ cpu ] cpu info" << std::endl;
	std::cout << "[ rm  ] RAM memory info" << std::endl;
	std::cout << "[ vm  ] Virtual memory info" << std::endl;
	std::cout << "[ hm  ] Hard Drive info" << std::endl;
	std::cout << "[ net ] networks info" << std::endl;
	std::cout << "[ uni ] magic unicorn" << std::endl << std::endl;

	std::cout << "Flags must be separated by spaces" << std::endl << std::endl;

	std::cout << "EXAMPLE (text mode)   : " << "ft_gkrellm -t \"o hu d rm vm\"" << std::endl;
	std::cout << "EXAMPLE (graphic mode): " << "ft_gkrellm -v \"o hu d rm vm\"" << std::endl << std::endl;
	exit(0);
}

int		main(int argc, char **argv)
{
	std::string flag = "";
	bool all = true;;

	if (argc < 2 && argv[0] != NULL){
		usage();
	}
	if (argc >= 3 && !(all = false)) {
		if (argv[2][0] == '\0')
			usage();
		flag = std::string(argv[2]);
	}

	if (!(strcmp("-v", argv[1]))) {
		Cor	prog(true, all, flag);
		prog.loop();
	}
	else if (!(strcmp("-t", argv[1]))) {
		Cor	prog(false, all, flag);
		prog.loop();
	}
	else
		usage();
	return (0);
}
