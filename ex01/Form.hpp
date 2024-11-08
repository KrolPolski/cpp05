/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:33:54 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 15:07:07 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_isSigned {false};
		const int			_gradeToSign;
		const int			_gradeToExecute;
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
		Form();
		Form(std::string name, int toSign, int toExecute);
		Form(const Form& other);
		Form& operator=(const Form& other) = delete;
		int getGradeToSign() const; 
		int getGradeToExecute() const;
		bool getIsSigned() const;
		const std::string getName() const;
		void beSigned(Bureaucrat& drone);
		~Form();
};

std::ostream& operator<<(std::ostream& out, const Form& someForm);