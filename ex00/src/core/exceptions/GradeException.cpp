/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:22:19 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/25 14:24:53 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high (minimum grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low (maximum grade is 150)";
}
