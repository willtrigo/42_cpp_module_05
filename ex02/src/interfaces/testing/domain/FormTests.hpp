/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormTests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:17:04 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/25 16:26:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_TESTS_HPP
#define FORM_TESTS_HPP

class FormTests {
 public:
  static void createTestSuite();

 private:
  FormTests();
  FormTests(const FormTests&);
  ~FormTests();

  FormTests& operator=(const FormTests&);

  static void testBasicFunctionality();
};

#endif // FORM_TESTS_HPP
