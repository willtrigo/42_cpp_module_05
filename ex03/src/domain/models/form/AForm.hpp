/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:21:54 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:00:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include <exception>
#include <string>

class AForm {
 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class AFormSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class AFormNotSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class AFormExecutedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  explicit AForm(const std::string& name, int gradeToSign, int gradeToExecute);
  AForm(const AForm& other);
  virtual ~AForm();

  AForm& operator=(const AForm& other);

  virtual AForm* clone() const = 0;

  const std::string getName() const throw();
  int getGradeToSign() const throw();
  int getGradeToExecute() const throw();
  bool isSigned() const throw();
  bool isExecuted() const throw();

  void markAsExecuted() const throw();
  void markAsSigned() const throw();

  void beSigned(Bureaucrat& bureaucrat);
  bool canBeSignedBy(const Bureaucrat& executor) const throw();
  bool canBeExecutedBy(const Bureaucrat& executor) const throw();
  bool isValidForSign() const throw();
  bool isValidForExecution() const throw();

  void execute(const Bureaucrat& executor) const;
  virtual void executeTask() const = 0;

 private:
  static const int HIGHEST_GRADE = 150;
  static const int LOWEST_GRADE = 1;

  mutable bool m_signed;
  mutable bool m_executed;

  const std::string m_name;
  const int m_gradeToSign;
  const int m_gradeToExecute;

  void validateAForm(int gradeToSign, int gradeToExecute) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP
