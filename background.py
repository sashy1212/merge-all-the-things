import cv2
# THIS IS MY WEBCAM
cap = cv2.VideoCapture(0)

#Repeat loop for when the webcam is open
while cap.isOpened():
    ret, back = cap.read() #HERE IS AM SIMPLY READING FROM MY WEBCAM
    if ret:
        # back is what the camera is reading
        cv2.imshow("image", back)
        if cv2.waitKey(5) == ord('q'):
            # save the image
            cv2.imwrite('image.jpg', back)
            break

#Releasing the lock
cap.release()
cv2.destroyAllWindows()
