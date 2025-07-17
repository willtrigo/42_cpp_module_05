/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:06:19 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/17 08:59:25 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "domain/models/form/AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();

  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

  void executeTask() const;

 private:
  static const std::string DEFAULT_TARGET;
  static const std::string DEFAULT_FORM_NAME;
  static const int GRADE_TO_SIGN = 25;
  static const int GRADE_TO_EXECUTE = 5;
  std::string m_target;

  PresidentialPardonForm();
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
