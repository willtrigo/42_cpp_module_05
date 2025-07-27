/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:15:00 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 14:38:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/Form.hpp"
#include <string>

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
  : m_signed(false),
    m_executed(false),
    m_name(name),
    m_gradeToSign(gradeToSign),
    m_gradeToExecute(gradeToExecute) {
   validateForm(this->m_gradeToSign, this->m_gradeToExecute);
}

Form::Form(const Form& other)
  : m_signed(other.m_signed),
    m_executed(other.m_executed),
    m_name(other.m_name),
    m_gradeToSign(other.m_gradeToSign),
    m_gradeToExecute(other.m_gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
  if (this != &other) {
    const_cast<std::string&>(this->m_name) = other.m_name;
    const_cast<int&>(this->m_gradeToSign) = other.m_gradeToSign;
    const_cast<int&>(this->m_gradeToExecute) = other.m_gradeToExecute;
    this->m_signed = other.m_signed;
    this->m_executed = other.m_executed;
  }
  return *this;
}
