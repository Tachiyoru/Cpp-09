/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:25:31 by sleon             #+#    #+#             */
/*   Updated: 2023/05/31 11:46:21 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange	Converter;

		Converter.storeInfile();
		Converter.display(av[1]);
	}
	else
		std::cout<<"Run as : btc <infile>"<<std::endl;
}
