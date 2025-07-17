/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:42:55 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/17 11:28:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
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

  const std::string getName() const throw();
  int getGradeToSign() const throw();
  int getGradeToExecute() const throw();
  bool isSigned() const throw();
  bool isExecuted() const throw();

  void beSigned(Bureaucrat& bureaucrat);

  void execute(const Bureaucrat& executor) const;

 protected:
  virtual void executeTask() const = 0;

 private:
  AForm();

  void validateAForm(int gradeToSign, int gradeToExecute) const;

  static const std::string DEFAULT_FORM_NAME;
  static const int DEFAULT_GRADE_TO_EXECUTE = 150;
  static const int DEFAULT_GRADE_TO_SIGN = 150;
  static const int HIGHEST_GRADE = 150;
  static const int LOWEST_GRADE = 1;

  const std::string m_name;
  const int m_gradeToSign;
  const int m_gradeToExecute;
  bool m_signed;
  mutable bool m_executed;
};

#endif // AFORM_HPP
