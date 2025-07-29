/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:23:49 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 14:36:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/bureaucrat/Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high (minimum grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low (maximum grade is 150)";
}
