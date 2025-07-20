/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteFormCommand.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:03:18 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/19 23:05:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/commands/ExecuteFormCommand.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"

ExecuteFormCommand::ExecuteFormCommand(const AForm& form, const Bureaucrat& executor)
  : m_form(&form),
    m_executor(&executor) {}

ExecuteFormCommand::ExecuteFormCommand(const ExecuteFormCommand& other)
  : m_form(other.m_form),
    m_executor(other.m_executor) {}

ExecuteFormCommand::~ExecuteFormCommand() {}

ExecuteFormCommand& ExecuteFormCommand::operator=(const ExecuteFormCommand& other) {
  if (this != &other) {
    this->m_form = other.m_form;
    this->m_executor = other.m_executor;
  }
  return *this;
}
