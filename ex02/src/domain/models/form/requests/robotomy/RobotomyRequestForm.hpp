/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:08:10 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 16:35:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "domain/models/form/AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();

  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

  void executeTask() const;

 private:
  static const std::string DEFAULT_TARGET;
  static const std::string DEFAULT_FORM_NAME;
  static const int GRADE_TO_SIGN = 72;
  static const int GRADE_TO_EXECUTE = 45;
  std::string m_target;

  RobotomyRequestForm();
};

#endif // ROBOTOMY_REQUEST_FORM_HPP
