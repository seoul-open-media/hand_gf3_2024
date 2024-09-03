function multiply(a, b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  }

function angle(a, b) {
    this.normalizedA = 0
    this.normalizedB = 0

    a.forEach(function (el) {
        this.normalizedA += el * el
    })
    b.forEach(function (el) {
        this.normalizedB += el * el
    })

    normalizedA = Math.sqrt(normalizedA)
    normalizedB = Math.sqrt(normalizedB)

    return (multiply(a, b) / (normalizedA * normalizedB))
}

const Leap = require('leapjs');
const controller = new Leap.Controller();

controller.loop(function (frame) {

            if (frame.hands[0]) {
                const palm = frame.hands[0].palmNormal
                const arm = frame.hands[0].arm.direction()
                console.log(frame.hands[0].palmPosition)
                
                console.log(palm)
                console.log(arm)
                console.log(angle(palm, arm))

                console.log('\n')
            }
})