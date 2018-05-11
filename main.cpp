#include "encoder.h"
#include "decoder.h"
#include "channel.h"
#include "detail.h"
#include <vector>
#include <string>
#include <iostream>

int main() {
  /* decide various noise levels for simulation */
  const std::vector<double> different_noise_levels = {0.001, 0.01, 0.1, 0.2, 0.3, 0.4, 0.5};
  for (double noise_level : different_noise_levels) {
    /* construct a noisy channel with the given bit-flip probability */
    channel noisy_channel(noise_level);
    /* choose a test message to transmit */
    const std::string test_message = "this is a test message to transmit over the noisy channel";
    std::vector<uint8_t> test_message_bytes(std::begin(test_message), std::end(test_message));
    /* perform encoding and "transmission" */
    encoder enc;
    for (uint8_t message : test_message_bytes) {
      codeword code = enc.encode(message); /* map the message to a codeword */
      noisy_channel.send(code); /* send the data */
    }
    /* perform decoding */
    decoder dec;
    std::vector<uint8_t> received_message;
    while (true) {
      codeword code;
      if (!noisy_channel.receive(&code)) {
        break; /* all data read */
      }
      uint8_t message = dec.decode(code);
      received_message.push_back(message);
    }
    /* compare received to sent message */
    size_t error_count = 0;
    for (size_t i = 0; i < test_message_bytes.size(); ++i) {
      error_count += detail::hamming_distance(test_message_bytes[i], received_message[i]);
    }
    std::cout << "TX Errors: " << noisy_channel.get_error_count();
    std::cout << ", RX Errors: " << error_count;
    std::cout << ", Noise: " << noise_level << std::endl;
  }
}
