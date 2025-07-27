/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratTests.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:16:45 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 14:13:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_TESTS_HPP
#define BUREAUCRAT_TESTS_HPP

class BureaucratTests {
 public:
  static void createTestSuite();

 private:
  BureaucratTests(const BureaucratTests&);
  ~BureaucratTests();

  BureaucratTests& operator=(const BureaucratTests&);

  static void testBasicFuntionality();
  static void testGradeManipulation();
  static void testInvalidConstruction();
  static void testBoundaryConditions();
  static void testCopyOperations();
};

#endif // BUREAUCRAT_TESTS_HPP
