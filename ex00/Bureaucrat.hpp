/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:32 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/05 17:06:58 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
class Bureaucrat
{
private:
	const std::string	name;
	int			 		grade;
public:
	Bureaucrat(int grade);
	~Bureaucrat();
	int getGrade() const;
	const std::string getName() const;
};


