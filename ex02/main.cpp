/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:13 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 18:22:53 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <ctime>

int main(void)
{
	//ensures we have a new random seed each time we run
	srand(static_cast<unsigned int>(time(0)));
	//Confirm abstract form:
	//AForm test;
	std::cout << "\n\033[31mPrepare yourself for the tests of the Shrubbery!\033[0m\n" << std::endl;	
	{	
		Bureaucrat drone;
		ShrubberyCreationForm test;
		std::cout << "We have made a Shrubbery form and a drone. Woo.\nThe drone shouldn't be able to execute this form because it hasn't been signed yet.\n" << std::endl;
		try
		{
			drone.executeForm(test);
		}
		catch (const AForm::FormNotSignedException& e)
		{
			std::cout << e.what() << std::endl;
		}
		Bureaucrat SirRobin("Sir Robin", 145);
		std::cout << SirRobin.getName() << " should be able to sign it, but not execute it since his grade is "	<< SirRobin.getGrade() << "\n" << std::endl;
		SirRobin.signForm(test);
		try
		{
			SirRobin.executeForm(test);
		}
		catch (const AForm::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
		Bureaucrat SirLancelot("Sir Lancelot", 100);
		SirLancelot.executeForm(test);
		ShrubberyCreationForm myHouse("MyHouse");
		SirLancelot.signForm(myHouse);
		SirLancelot.executeForm(myHouse);
		std::cout << "\n\033[31mPrepare yourself for the tests of the Robotomizer 3000!\033[0m\n" << std::endl;	
	}
	{
		Bureaucrat drone;
		RobotomyRequestForm Threepio("Threepio");
		std::cout << "The drone should fail to sign or execute the form because his grade is too low:\n" << std::endl;
		try
		{
			drone.signForm(Threepio);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			drone.executeForm(Threepio);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		Bureaucrat Ugnaught("Ugnaught", 45);
		try
		{
			Ugnaught.signForm(Threepio);
			Ugnaught.executeForm(Threepio);
			Ugnaught.executeForm(Threepio);
			Ugnaught.executeForm(Threepio);
			Ugnaught.executeForm(Threepio);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
	std::cout << "\n\033[31mPrepare yourself for the tests of the Presidential Pardon System!\033[0m\n" << std::endl;	
}