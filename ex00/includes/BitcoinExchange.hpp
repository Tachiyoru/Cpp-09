/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:57:22 by sleon             #+#    #+#             */
/*   Updated: 2023/05/31 10:57:46 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _dataMap;

	public:

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &toCopy);

		void	storeInfile();
		void	display(char *infile);
		float	getExchangeRate(std::string);
		int		parseValue(float value) const;
		int		parseDate(std::string date) const;
		bool	checkFormat(std::string date) const;
		bool	isLeapYear(int year) const;
};

#endif
