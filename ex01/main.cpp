/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:11:12 by sleon             #+#    #+#             */
/*   Updated: 2023/05/31 12:19:39 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN			calculator;
		std::string	arg = argv[1];

		if (calculator.calculate(arg))
			return 1;
	}
	else
		std::cout<<"Run as : RPN \"3 7 +\" for example"<<std::endl;
	return 0;
}
