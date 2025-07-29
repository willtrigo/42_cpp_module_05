/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignFormCommand.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:07:46 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:55:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/commands/SignFormCommand.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"

SignFormCommand::SignFormCommand(const AForm& form, const Bureaucrat& executor)
  : m_form(&form),
    m_executor(&executor) {}

SignFormCommand::SignFormCommand(const SignFormCommand& other)
  : m_form(other.m_form),
    m_executor(other.m_executor) {}

SignFormCommand::~SignFormCommand() {}

SignFormCommand& SignFormCommand::operator=(const SignFormCommand& other) {
  if (this != &other) {
    this->m_form = other.m_form;
    this->m_executor = other.m_executor;
  }
  return *this;
}
