/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:36:00 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/02 16:53:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/form/Form.hpp"

const std::string Form::DEFAULT_FORM_NAME = "Unamed Form";
const int Form::DEFAULT_GRADE_TO_EXECUTE = 150;
const int Form::DEFAULT_GRADE_TO_SIGN = 150;

Form::Form()
  : m_name(DEFAULT_FORM_NAME),
    m_gradeToSign(DEFAULT_GRADE_TO_SIGN),
    m_gradeToExecute(DEFAULT_GRADE_TO_EXECUTE),
    m_signed(false) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
  : m_name(name),
    m_gradeToSign(gradeToSign),
    m_gradeToExecute(gradeToExecute),
    m_signed(false) {

}

Form::Form(const Form& other)
  : m_name(other.m_name),
    m_gradeToSign(other.m_gradeToSign),
    m_gradeToExecute(other.m_gradeToExecute),
    m_signed(other.m_signed) {}

Form& Form::operator=(const Form& other) {
  if (this != &other) {
    const_cast<std::string&>(this->m_name) = other.m_name;
    const_cast<int&>(this->m_gradeToSign) = other.m_gradeToSign;
    const_cast<int&>(this->m_gradeToExecute) = other.m_gradeToExecute;
    this->m_signed = other.m_signed;
  }
  return *this;
}

Form::~Form() {}
