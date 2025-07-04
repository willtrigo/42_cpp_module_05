/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratUtility.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:51:35 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/04 19:20:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

std::string Bureaucrat::getName() const {
  return this->m_name;
}

int Bureaucrat::getGrade() const {
  return this->m_grade;
}

void Bureaucrat::incrementGrade() {
  validateGrade(this->m_grade - GRADE_SHIFT_AMOUNT);
  --this->m_grade;
}

void Bureaucrat::decrementGrade() {
  validateGrade(this->m_grade + GRADE_SHIFT_AMOUNT);
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
  return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
