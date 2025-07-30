/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:03:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/30 16:34:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class AForm;

class Bureaucrat {
 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  ~Bureaucrat();

  Bureaucrat& operator=(const Bureaucrat& other);

  const std::string getName() const throw();
  int getGrade() const throw();

  void incrementGrade();
  void decrementGrade();

  void signForm(AForm& form);

 private:
  const std::string m_name;
  int m_grade;

  static const int HIGHEST_GRADE = 1;
  static const int LOWEST_GRADE = 150;
  static const int GRADE_SHIFT_AMOUNT = 1;

  void validateGrade(int grade) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif // BUREAUCRAT_HPP
