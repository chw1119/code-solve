import os
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from PIL import Image
from io import BytesIO
import time

# Define the path to the WebDriver
webdriver_path = './chromedriver-linux64/chromedriver'  # Update this path to the extracted ChromeDriver

# Define the path to Chrome binary
chrome_binary_path = './chrome-linux64/chrome'  # Update this path to the extracted Chrome

# Ensure ChromeDriver path is correct
if not os.path.isfile(webdriver_path):
    raise FileNotFoundError(f"ChromeDriver not found at {webdriver_path}")

# Ensure Chrome binary path is correct
if not os.path.isfile(chrome_binary_path):
    raise FileNotFoundError(f"Chrome binary not found at {chrome_binary_path}")

# Setup Chrome options
chrome_options = Options()
chrome_options.add_argument('--headless')  # Run in headless mode (no GUI)
chrome_options.add_argument('--disable-gpu')
chrome_options.add_argument('--window-size=1920x5000')
chrome_options.binary_location = chrome_binary_path  # Set the binary location
chrome_options.add_argument("--disable-blink-features=AutomationControlled")  # Prevent detection as automation
chrome_options.add_argument("user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36")  # Set user-agent

# Initialize the WebDriver
service = Service(webdriver_path)
try:
    driver = webdriver.Chrome(service=service, options=chrome_options)
except Exception as e:
    print(f"Error initializing WebDriver: {e}")
    raise

# Directory containing the folders
base_dir = './beakjoon/problems'

# Get the list of folder names
folders = [f.name for f in os.scandir(base_dir) if f.is_dir()]

for folder in folders:
    # Construct the URL
    url = f'https://www.acmicpc.net/problem/{folder}'

    # Open the URL
    driver.get(url)

    # Wait for the page to load and the element to be present
    try:
        element = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.XPATH, '/html/body/div[2]/div[2]/div[3]'))
        )
        time.sleep(2)
        print(f"Element found for {folder}")

        # Find the element and take a screenshot
        location = element.location
        size = element.size
        screenshot = driver.get_screenshot_as_png()

        # Create an image from the screenshot
        im = Image.open(BytesIO(screenshot))

        # Define the bounding box for the element with bounds checking
        left = max(location['x'], 0)
        top = max(location['y'], 0)
        right = min(location['x'] + size['width'], im.width)
        bottom = min(location['y'] + size['height'], im.height)

        # Ensure the dimensions are valid
        if left < right and top < bottom:
            print(f"Cropping dimensions for {folder}: left={left}, top={top}, right={right}, bottom={bottom}")
            # Crop the image to the bounding box
            im = im.crop((left, top, right, bottom))
            # Save the image
            image_path = os.path.join(base_dir, folder, f'{folder}.png')
            im.save(image_path)
            print(f'Saved image for {folder} at {image_path}')
        else:
            print(f"Invalid cropping dimensions for {folder}: left={left}, top={top}, right={right}, bottom={bottom}")
    except Exception as e:
        print(f'Failed to capture image for {folder}: {e}')
        # Save the page source for debugging
        page_source_path = os.path.join(base_dir, folder, f'{folder}.html')
        with open(page_source_path, 'w') as f:
            f.write(driver.page_source)
        print(f'Saved page source for {folder} at {page_source_path}')

# Close the WebDriver
driver.quit()
