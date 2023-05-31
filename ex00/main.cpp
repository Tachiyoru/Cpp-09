/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:25:31 by sleon             #+#    #+#             */
/*   Updated: 2023/05/30 17:29:22 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange	Converter;
		try{
			Converter.storeInfile();
			Converter.display(av[1]);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cout<<"Run as : btc <infile>"<<std::endl;
}
