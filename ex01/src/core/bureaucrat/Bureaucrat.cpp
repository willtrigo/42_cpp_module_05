/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:32:49 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/30 15:34:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/bureaucrat/Bureaucrat.hpp"

const std::string Bureaucrat::DEFAULT_NAME = "Unnamed Bureaucrat";
const int Bureaucrat::DEFAULT_GRADE = 150;

Bureaucrat::Bureaucrat()
  : m_name(DEFAULT_NAME),
    m_grade(DEFAULT_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
  : m_name(name),
    m_grade(grade) {
  validateGrade(m_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
  : m_name(other.m_name),
    m_grade(other.m_grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    const_cast<std::string&>(this->m_name) = other.m_name;
    this->m_grade = other.m_grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}
