/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:13 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 13:28:13 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		std::cout << "Testing Default Constructor" << std::endl;
		Bureaucrat drone;
		std::cout << drone << std::endl;
		std::cout << "Testing too high a grade in the constructor, should throw an exception" << std::endl;
		Bureaucrat MrPower("Mr. Power", 0);
	}
	
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "Testing too low a grade in the constructor, should throw an exception" << std::endl;
		Bureaucrat Peon("Peon", 151);
	}
	
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Testing name and grade constructor" << std::endl;
		Bureaucrat Bill("Bill", 10);
		std::cout << Bill << std::endl;
		std::cout << "Bill needs a promotion" << std::endl;
		Bill.IncrementGrade();
		std::cout << Bill << std::endl;
		std::cout << "Now we increase his grade until we get an exception" << std::endl;
		for (size_t i = 0; i < 9; i++)
		{
			Bill.IncrementGrade();
			std::cout << Bill << std::endl;
		}
	}
	
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Let's make a minimum grade bureaucrat and try to decrement him" << std::endl;
		Bureaucrat drone;
		std::cout << drone << std::endl;
		drone.DecrementGrade();
	}
	
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}