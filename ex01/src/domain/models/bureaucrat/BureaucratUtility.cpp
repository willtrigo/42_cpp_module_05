/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratUtility.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:13:55 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/26 21:57:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "infrastructure/io/BureaucratPrinter.hpp"
#include <iostream>
#include <string>

std::string Bureaucrat::getName() const {
  return this->m_name;
}

int Bureaucrat::getGrade() const {
  return this->m_grade;
}

void Bureaucrat::incrementGrade() {
  validateGrade(this->m_grade - 1);
  --this->m_grade;
}

void Bureaucrat::decrementGrade() {
  validateGrade(this->m_grade + 1);
  ++this->m_grade;
}

void Bureaucrat::validateGrade(int grade) const {
  if (grade < HIGHEST_GRADE)
  {
    throw GradeTooHighException();
  }
  else if (grade > LOWEST_GRADE)
  {
    throw GradeTooLowException();
  }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  return BureaucratPrinter::print(os, bureaucrat);
}
