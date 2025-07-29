/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:23:34 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 14:35:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

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

  std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

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
