/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:38:38 by sleon             #+#    #+#             */
/*   Updated: 2023/05/31 14:47:03 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (sorting(argv))
			return 1;
	}
	else
		std::cout<<"Run as : PmergerMe \"\" for example"<<std::endl;
	return 0;
}
