/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:38:38 by sleon             #+#    #+#             */
/*   Updated: 2023/06/12 14:36:45 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	notInt(char **arg){
	for (int j = 1; arg[j]; ++j)
	{
		for (int i = 0; arg[j][i]; ++i)
			{
				if (arg[j][i] < '0' || arg[j][i] > '9' )
					return 1;
			}
	}
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (notInt(argv))
			return (std::cout<<"Non numerical argument"<<std::endl, 1);
		if (sorting(argv))
			return 1;
	}
	else
		std::cout<<"Run as : PmergerMe 4 6 8 3 5 for example"<<std::endl;
	return 0;
}
