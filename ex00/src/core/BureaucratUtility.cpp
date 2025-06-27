/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratUtility.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:51:35 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/26 23:52:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

const int Bureaucrat::HIGHEST_GRADE = 1;
const int Bureaucrat::LOWEST_GRADE = 150;

std::string Bureaucrat::getName() const {
  return m_name;
}

int Bureaucrat::getGrade() const {
  return m_grade;
}

void Bureaucrat::incrementGrade() {
  validateGrade(m_grade + 1);
  --m_grade;
}

void Bureaucrat::decrementGrade() {
  validateGrade(m_grade - 1);
  ++m_grade;
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
