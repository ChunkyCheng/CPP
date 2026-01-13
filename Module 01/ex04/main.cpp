/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:18:18 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/13 23:33:16 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

static bool	open_fstreams(std::ifstream& infile, std::ofstream& outfile,
std::string filepath)
{
	infile.open(filepath.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error opening infile" << std::endl;
		return (false);
	}
	outfile.open((filepath + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error opening outfile" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		input;
	std::string		target;
	std::string		replacement;
	size_t			pos;

	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
		return (1);
	}
	if (open_fstreams(infile, outfile, argv[1]) == false)
		return (2);
	target = argv[2];
	replacement = argv[3];
	while (std::getline(infile, input))
	{
		pos = input.find(target);
		while (pos != std::string::npos)
		{
			outfile << input.substr(0, pos);
			outfile << replacement;
			input.erase(0, pos + target.length());
			pos = input.find(target);
		}
		outfile << input;
		if (!infile.eof())	
			outfile << "\n";
	}
}
