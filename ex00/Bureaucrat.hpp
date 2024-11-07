/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:32 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/07 17:15:02 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

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
			virtual const char *what() const throw();
			~GradeTooHighException() = default;
	};
	
	class GradeTooLowException : std::exception
	{
		public:
			GradeTooLowException() = default;
			virtual const char *what() const throw();
			~GradeTooLowException() = default;
	};

	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	void IncrementGrade();
	void DecrementGrade();
	~Bureaucrat();
	int getGrade() const;
	const std::string getName() const;
};


