/******************************************************************************
 * MIT License

 * Copyright (c) 2019 Naman Gupta

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 ******************************************************************************/

/**
 * @file      MockDetectHuman.hpp
 * @author    Naman Gupta (namangupta98) Navigator
 * @copyright MIT License
 * @brief     MockDetectHuman Class declaration
 * @detail    Declared mock functions Class to test gmock
 */

#ifndef INCLUDE_MOCKDETECTHUMAN_HPP_
#define INCLUDE_MOCKDETECTHUMAN_HPP_

#include <string>
#include "DetectHuman.hpp"
#include "gmock/gmock.h"

/**
 * @brief class DetectHuman
 * The class DetectHuman uses a trained SVM model to detect humans in an image 
 * and returns the pixel coordinates of the bounding boxes containing humans in
 * an image
 */
class MockDetectHuman : public DetectHuman {
 public:
	/**
   * @brief constructor DetectHuman
   * @param none
   * @return none
   */
  MockDetectHuman() : DetectHuman() {}
  /**
   * @brief Container to store SVM classifier model
   */

  MOCK_METHOD0(setDefaultSVM, void());
  /**
   * @brief Method sets the SVM model trained by TrainSVM class
   * @param customSVMFile of type string
   * @return none
   * Path of custom trained SVM model should be provided to the method
   * in order to use custom SVM with HOGDescriptor
   */

  MOCK_METHOD1(setCustomSVM, void(std::string customSVMFile));
  /**
   * @brief Function checks either the file already exists or not
   * @param fileName of type string
   * @return true if the file already exists and false if does not exist
   */

  MOCK_METHOD1(fileExist, bool(const std::string& filename));
  /**
   * @brief destructor DetectHuman
   * @param none
   * @return none
   */

  ~MockDetectHuman();
};

#endif  // INCLUDE_MOCKDETECTHUMAN_HPP_
