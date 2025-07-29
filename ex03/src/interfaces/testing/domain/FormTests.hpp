/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormTests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:38:03 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:05:13 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_TESTS_HPP
#define FORM_TESTS_HPP

class FormTests {
 public:
  static void createTestSuite();

 private:
  FormTests(const FormTests&);
  ~FormTests();

  FormTests& operator=(const FormTests&);

  static void testFormBasicFunctionality();
  static void testFormCopyOperations();
};

#endif // FORM_TESTS_HPP
