/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:32 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 17:24:26 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
private:
	const std::string	_name;
	int			 		_grade;
public:
	class GradeTooHighException : std::exception
	{
		public:
			GradeTooHighException() = default;
			virtual const char *what() const noexcept;
			~GradeTooHighException() = default;
	};
	
	class GradeTooLowException : std::exception
	{
		public:
			GradeTooLowException() = default;
			virtual const char *what() const noexcept;
			~GradeTooLowException() = default;
	};
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade); 
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	void IncrementGrade();
	void DecrementGrade();
	~Bureaucrat();
	int getGrade() const;
	const std::string getName() const;
	void signForm(AForm& form);
	void executeForm(const AForm& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& drone);

