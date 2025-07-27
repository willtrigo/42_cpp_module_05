/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignFormCommand.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:11:31 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 13:24:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGN_FORM_COMMAND_HPP
#define SIGN_FORM_COMMAND_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/Form.hpp"

class SignFormCommand {
 public:
  SignFormCommand(const Form& form, const Bureaucrat& executor);
  SignFormCommand(const SignFormCommand& other);
  ~SignFormCommand();

  SignFormCommand& operator=(const SignFormCommand& other);

  void execute() const;

 private:
  const Form* m_form;
  const Bureaucrat* m_executor;

  void validateSignPreconditions() const;
  void performSign() const;
  void handleSignSuccess() const;
  void logSignSuccess() const;
};

#endif // SIGN_FORM_COMMAND_HPP
