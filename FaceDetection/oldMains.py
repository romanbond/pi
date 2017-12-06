import cv2
import numpy as np

#refs: https://stackoverflow.com/questions/34871294/full-body-detection-and-tracking-using-opencvpython-2-7
#refs: https://pythonprogramming.net/haar-cascade-face-eye-detection-python-opencv-tutorial/

# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades
# https://github.com/opencv/opencv/tree/master/data/haarcascades

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
#eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')
glasses_cascade = cv2.CascadeClassifier('haarcascade_eye_tree_eyeglasses.xml')

cap = cv2.VideoCapture(0)

def inside(r, q):
    rx, ry, rw, rh = r
    qx, qy, qw, qh = q
    return rx > qx and ry > qy and rx + rw < qx + qw and ry + rh < qy + qh

def draw_detections(img, rects, thickness = 1):
    for x, y, w, h in rects:
        # the HOG detector returns slightly larger rectangles than the real objects.
        # so we slightly shrink the rectangles to get a nicer output.
        pad_w, pad_h = int(0.15*w), int(0.05*h)
        cv2.rectangle(img, (x+pad_w, y+pad_h), (x+w-pad_w, y+h-pad_h), (0, 0, 255), 3)

while 1:
    ret, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    #Face_cascade
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    hog = cv2.HOGDescriptor()
    hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

    #Face Cascade Loop
    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)
        roi_gray = gray[y:y + h, x:x + w]
        roi_color = img[y:y + h, x:x + w]
        #Eye_Cascade
        #eyes = eye_cascade.detectMultiScale(roi_gray)
        eyesG = glasses_cascade.detectMultiScale(roi_gray)
        # #Eye Cascade Loop
        for (ex, ey, ew, eh) in eyesG:
            roi_gray = gray[y:y + h, x:x + w]
            cv2.rectangle(roi_color, (ex, ey), (ex + ew, ey + eh), (0, 255, 0), 2)
        # Glasses Cascade Loop
        # for (ex, ey, ew, eh) in eyes:
        #     roi_gray = gray[y:y + h, x:x + w]
        #     cv2.rectangle(roi_color, (ex, ey), (ex + ew, ey + eh), (0, 255, 0), 2)

    found, w = hog.detectMultiScale(img, winStride=(8, 8), padding=(32, 32), scale=1.05)
    draw_detections(img, found)

    cv2.namedWindow('img', cv2.WINDOW_NORMAL)  # Create window with freedom of dimensions
    imS = cv2.resize(img, (960, 540))  # Resize image
    cv2.imshow('img', imS)
    k = cv2.waitKey(30) & 0xff
    # Esc button
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()