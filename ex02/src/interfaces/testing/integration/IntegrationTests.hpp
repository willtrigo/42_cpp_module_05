/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegrationTests.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:58:09 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/25 23:21:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRATION_TESTS_HPP
#define INTEGRATION_TESTS_HPP

class IntegrationTests {
 public:
  static void createTestSuite();

 private:
  IntegrationTests();
  IntegrationTests(const IntegrationTests&);
  ~IntegrationTests();

  IntegrationTests& operator=(const IntegrationTests&);

  static void testSuccessfulSignedExecuteForm();
  static void testInsufficientGradeToSigingForm();
  static void testAlreadySignedForm();
  static void testInsufficientGradeToExecuteForm();
  static void testAlreadyExecuteForm();
};

#endif // INTEGRATION_TESTS_HPP
