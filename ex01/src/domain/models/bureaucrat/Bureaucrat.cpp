/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:13:39 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/26 20:35:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
  : m_name(name),
    m_grade(grade) {
  validateGrade(this->m_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
  : m_name(other.m_name),
    m_grade(other.m_grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    const_cast<std::string&>(this->m_name) = other.m_name;
    this->m_grade = other.m_grade;
  }
  return *this;
}
